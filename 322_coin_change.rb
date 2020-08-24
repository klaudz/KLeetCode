#!/usr/bin/ruby

$integer_max = 1 << 32

# @param {Integer[]} coins
# @param {Integer} amount
# @return {Integer}
def coin_change(coins, amount)

    dp_cache = {}

    def dp(n, coins, amount, dp_cache)
        return 0 if n == 0
        return -1 if n < 0
        res = dp_cache[n]
        return res unless res.nil?
        res = $integer_max
        for coin in coins
            sub_res = dp(n - coin, coins, amount, dp_cache)
            next if sub_res == -1
            res = [ res, sub_res + 1 ].min
        end
        res = (res == $integer_max) ? -1 : res
        dp_cache[n] = res
        res
    end

    dp(amount, coins, amount, dp_cache)
end

def _main_

    ret = coin_change([ 1, 2, 5 ], 11)
    puts "#{ret}"
    
    ret = coin_change([ 2 ], 3)
    puts "#{ret}"

end

_main_