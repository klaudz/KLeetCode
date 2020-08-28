#!/usr/bin/ruby

require_relative 'common_ruby/linked_list'

# @param {ListNode} head
# @return {Boolean}
def is_palindrome(head)
    return true if head.nil?
    is = true
    ordered_node = head
    head.reverse { |reversed_node|
        if ordered_node.val != reversed_node.val
            is = false
            # break
        end
        ordered_node = ordered_node.next
    }
    is
end

def _main_

    list = ListNode.new_from_array([ ])
    ret = is_palindrome(list)
    puts "#{ret}"

    list = ListNode.new_from_array([ 1, 2 ])
    ret = is_palindrome(list)
    puts "#{ret}"
        
    list = ListNode.new_from_array([ 1, 2, 2, 1 ])
    ret = is_palindrome(list)
    puts "#{ret}"

    list = ListNode.new_from_array([ 1, 2, 3, 2, 1 ])
    ret = is_palindrome(list)
    puts "#{ret}"

end

_main_
