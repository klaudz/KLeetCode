
class ListNode
    attr_accessor :val, :next
    def initialize(val = 0, _next = nil)
        @val = val
        @next = _next
    end
end

class ListNode
    def self.new_from_array(array)
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
end
