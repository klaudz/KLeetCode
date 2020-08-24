#!/usr/bin/ruby

require_relative 'common_ruby/tree'

def kth_smallest(root, k)
    ret = nil
    i = 0
    tree_search_dfs_inorder(root) { |val|
        ret = val if i + 1 == k
        i += 1
    }
    ret
end

def _main_

    tree = create_tree_from_numbers([ 3, 1, 4, nil, 2 ])
    ret = kth_smallest(tree, 1)
    puts "#{ret}"
        
    tree = create_tree_from_numbers([ 5, 3, 6, 2, 4, nil, nil, 1 ])
    ret = kth_smallest(tree, 3)
    puts "#{ret}"

end

_main_