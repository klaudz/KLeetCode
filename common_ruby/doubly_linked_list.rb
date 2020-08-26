
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
    def remove(node)
        @head = node.next if @head == node
        @tail = node.prev if @tail == node
        if node.equal?(@tail)
            @tail = node.prev
            puts "x"
        end
        node.prev.next = node.next if node.prev
        node.next.prev = node.prev if node.next
        node.prev = nil
        node.next = nil
    end
    def unshift(node)
        node.prev = nil
        node.next = @head
        @head.prev = node if @head
        @head = node
        @tail = node if @tail.nil?
    end
    def push(node)
        node.prev = @tail
        node.next = nil
        @tail.next = node if @tail
        @head = node if @head.nil?
        @tail = node
    end
    def description
        infos = []
        node = @head
        while node
            infos.push(node.value)
            node = node.next
        end
        "[ #{infos.join(", ")} ]"
    end
end