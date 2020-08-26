
class DoublyLinkedNode
    attr_accessor :value, :prev, :next
    def initialize(value, prev = nil, _next = nil)
        @value = value
        @prev = prev
        @next = _next
    end
end

class DoublyLinkedList
    attr_accessor :head, :tail
    def initialize(head = nil, tail = nil)
        @head = head
        @tail = tail
    end
    def self.new_from_array(array)
        head = nil
        tail = nil
        while array.count > 0
            value = array.shift
            prev = tail
            node = DoublyLinkedNode.new(value, prev)
            if head.nil?
                head = node
            else
                prev.next = node
            end
            tail = node
        end
        list = self.new(head, tail)
        list
    end
end