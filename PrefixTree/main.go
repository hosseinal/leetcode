type Node struct {
    children map[rune]*Node
    exists   bool
}

type PrefixTree struct {
    start *Node
}

func Constructor() PrefixTree {
    return PrefixTree{start: &Node{children: make(map[rune]*Node)}}
}

func (t *PrefixTree) Insert(word string) {
    cur := t.start
    for _, c := range word {
        if cur.children[c] == nil {
            cur.children[c] = &Node{children: make(map[rune]*Node)}
        }
        cur = cur.children[c]
    }
    cur.exists = true
}

func (t *PrefixTree) Search(word string) bool {
    cur := t.start
    for _, c := range word {
        if cur.children[c] == nil {
            return false
        }
        cur = cur.children[c]
    }
    return cur.exists
}

func (t *PrefixTree) StartsWith(prefix string) bool {
    cur := t.start
    for _, c := range prefix {
        if cur.children[c] == nil {
            return false
        }
        cur = cur.children[c]
    }
    return true
}

