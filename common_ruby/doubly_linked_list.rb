
class DoublyLinkedNode
    attr_accessor :value, :previous_node, :next_node
    def initialize(value, previous_node = nil, next_node = nil)
        @value = value
        @previous_node = previous_node
        @next_node = next_node
    end
end

class DoublyLinkedList
    attr_accessor :head_node, :tail_node
    def initialize(head_node = nil, tail_node = nil)
        @head_node = head_node
        @tail_node = tail_node
    end
    def self.new_from_array(array)
        head_node = nil
        tail_node = nil
        while array.count > 0
            value = array.shift
            previous_node = tail_node
            node = DoublyLinkedNode.new(value, previous_node)
            if head_node.nil?
                head_node = node
            else
                previous_node.next_node = node
            end
            tail_node = node
        end
        list = self.new(head_node, tail_node)
        list
    end
end