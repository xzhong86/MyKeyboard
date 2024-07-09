
require 'ostruct'

class Regexp
  def full_match(str)
    m = self.match(str)
    m and m[0] == str
  end
end

class Keymap
  def initialize(keymap, keys = nil)
    if keys
      @type, @keys = keymap, keys
    elsif keymap =~ /(KEYMAP\w*)\s*\((.*)\)/m
      @type, keys = $1, $2.strip.split(/\n/)
      @keys = keys.map{ |ks| ks.strip.split(/\s*,\s*/) }
    else
      fail keymap
    end
  end
  def keys ; @keys end

  def map_key(kmap, &code)
    keep_keys  = kmap[:keep_keys]
    match_kept_keys = proc do |key|
      if ((keep_keys.kind_of?(Regexp) and keep_keys.full_match(key)) or
          (keep_keys.kind_of?(Array)  and keep_keys.include? key) or
          (keep_keys.kind_of?(String) and keep_keys == key ))
        key
      else
        nil
      end
    end
    trans_keys = kmap[:trans_keys]
    match_trans_keys = proc do |key|
      rule, new_key = *trans_keys
      if rule.kind_of? Regexp and new_key and rule.full_match(key)
        new_key
      else
        nil
      end
    end
    key_for_others = kmap[:others]

    keys = @keys.map do |ks|
      ks.map do |key|
        (kmap[key] || kmap[key.to_sym] ||
         (code && code.call(key)) ||
         match_kept_keys.call(key) ||
         match_trans_keys.call(key) ||
         key_for_others ||
         key)
      end
    end
    Keymap.new @type, keys
  end
  def merge(kmap_b)
    keys = @keys.map.with_index do |ks, ks_i|
      ks_b = kmap_b.keys[ks_i]
      ks.map.with_index do |k_a, k_i|
        k_b = ks_b[k_i]
        (k_a == "TRNS" or
         k_a == "NO" and k_b != "TRNS") ? k_b : k_a
      end
    end
    Keymap.new @type, keys
  end

  def to_code
    @type + '(' + @keys.flatten.join(', ') + ')'
  end
  def dump
    puts @type + '('
    @keys.each do |ks|
      puts "    " + ks.map{ |k| "%5s" % k }.join(', ')
    end
    puts ')'
  end
end

def Keymap.get_keymaps()
  k87 = Keymap.new("
  KEYMAP_K87(
    ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,    PSCR,SLCK,BRK,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,   INS, HOME,PGUP,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,   DEL, END, PGDN,
    LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,
    FN5, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          FN6,         UP,
    LCTL,LGUI,LALT,          FN1,                     FN0, RALT,RGUI,RCTL,   LEFT,DOWN,RGHT
  )")
  k60 = Keymap.new("
  KEYMAP_K60( ESC, 
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, 
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, 
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT, 
    LCTL,LGUI,LALT,               SPC,                RALT,RGUI,APP, RCTL  
  )")

  k60_num2fn = k60.map_key({
    '1' => 'F1', '2' => 'F2', '3' => 'F3', '4' => 'F4', '5' => 'F5', '6' => 'F6',
    '7' => 'F7', '8' => 'F8', '9' => 'F9', '0' => 'F10', MINS: 'F11', EQL: 'F12',
    others: 'TRNS'
  })
  k60_move = k60.map_key({
    I: 'UP', K: 'DOWN', J: 'LEFT', L: 'RGHT', U: 'PGUP', N: 'PGDN', H: 'HOME', O: 'END',
    others: 'TRNS'
  })

  k60_spcfn = k60.map_key({
    ESC: 'GRV', X: 'DEL', B: 'SPC', P: 'PSCR', COMM: 'BSPC', DOT: 'DEL',
    SCLN: 'NO', QUOT: 'NO', SLSH: 'NO',
    trans_keys: [/[A-Z]/, 'NO'],
    others: 'TRNS'
  }).merge(k60_num2fn).merge(k60_move)

  k60_f_edit = k60.map_key({
    D: 'LCTL', S: 'LSFT', A: 'LALT', W: 'TAB', COMM: 'BSPC', DOT: 'DEL',
    SCLN: 'NO', QUOT: 'NO', SLSH: 'NO',
    trans_keys: [/[A-Z]/, 'NO'],
    others: 'TRNS'
  }).merge(k60_move)

  maps = {
    k60: k60, k87: k87, k60_num2fn: k60_num2fn, k60_move: k60_move,
    k60_spcfn: k60_spcfn, k60_f_edit: k60_f_edit,
  }
  OpenStruct.new(maps)
end

if __FILE__ == $0
  keymaps  = Keymap.get_keymaps()
  keymap   = keymaps[:k60] # keymaps[:k87]
  keymap_1 = keymap.map_key({ 'I' => 'UP', 'K' => 'DOWN' })
  puts keymap_1.to_code
  keymap_1.dump
  keymap.map_key({ J: 'LEFT', K: 'DOWN', L: 'RGHT', keep_keys: /[LR](CTL|GUI|ALT)/,
                   trans_keys: [ /[QWERASDFZXCV]/, 'NO' ], others: 'TRNS' }
                 ).dump
  keymap.map_key({ J: 'LEFT', K: 'DOWN', L: 'RGHT', keep_keys: /[LR](CTL|GUI|ALT)/,
                   trans_keys: [ /[QWERASDFZXCV]/, 'NO' ], others: 'TRNS' }) do |key|
    key == 'APP' ? key : nil
  end.dump
end

