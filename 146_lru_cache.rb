#!/usr/bin/ruby

require_relative 'common_ruby/doubly_linked_list'

class LRUCache

=begin
    :type capacity: Integer
=end
    def initialize(capacity)
        @capacity = capacity
        @node_hash = {}
        @doubly_linked_list = DoublyLinkedList.new
    end

=begin
    :type key: Integer
    :rtype: Integer
=end
    def get(key)
        node = @node_hash[key]
        return -1 if node.nil?
        @doubly_linked_list.remove(node)
        @doubly_linked_list.unshift(node)
        node.value
    end

=begin
    :type key: Integer
    :type value: Integer
    :rtype: Void
=end
    def put(key, value)
        node = @node_hash[key]
        if node.nil?
            node = LRUCacheDoublyLinkedNode.new(value)
            node.key = key
            if @node_hash.count >= @capacity
                pop = @doubly_linked_list.tail
                @node_hash.delete(pop.key)
                @doubly_linked_list.remove(pop)
            end
            @node_hash[key] = node
        else
            node.value = value
            @doubly_linked_list.remove(node)
        end
        @doubly_linked_list.unshift(node)
    end
     
end

class LRUCacheDoublyLinkedNode < DoublyLinkedNode
    attr_accessor :key
end

def _main_

    cache = LRUCache.new(2)
    cache.put(1, 1);
    cache.put(2, 2);
    puts cache.get(1);
    cache.put(3, 3);
    puts cache.get(2);
    cache.put(4, 4);
    puts cache.get(1);
    puts cache.get(3);
    puts cache.get(4);

end

_main_
