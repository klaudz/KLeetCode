
require_relative 'list_node'

def create_linked_list_from_array(array)
    head = nil
    tail = nil
    while array.count > 0
        val = array.shift
        node = ListNode.new(val)
        if head.nil?
            head = node
        else
            tail.next = node
        end
        tail = node
    end
    head
end