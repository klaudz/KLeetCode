
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

class ListNode
    def each
        node = self
        while node
            yield(node)
            node = node.next
        end
    end
    def reverse
        self.class.reverse_node(self) { |node| yield(node) }
    end
    def self.reverse_node(node)
        return if node.nil?
        reverse_node(node.next) { |next_node| yield(next_node) }
        yield(node)
    end
end
