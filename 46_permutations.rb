#!/usr/bin/ruby

# @param {Integer[]} nums
# @return {Integer[][]}
def permute(nums)
    $tracks = []
    def _permute(nums, curr_track)
        if curr_track.count == nums.count
            $tracks.push(curr_track.dup)
            return
        end
        for i in 0..(nums.count - 1)
            num = nums[i]
            next if curr_track.include?(num)
            curr_track.push(num)
            _permute(nums, curr_track)
            curr_track.pop
        end
    end
    _permute(nums, [])
    $tracks
end

def _main_

    puts "#{permute([ 1, 2, 3 ])}"

end

_main_
