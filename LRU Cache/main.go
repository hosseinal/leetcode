type Node struct {
    key  int
    value int
    prev *Node
    next *Node
}

type LRUCache struct {
    capacity int
    cache map[int]*Node
    leastUsed *Node
    lastUsed *Node
}

func Constructor(capacity int) LRUCache {
    cache := LRUCache {
        capacity: capacity,
        leastUsed : &Node{},
        lastUsed : &Node{},
        cache: make(map[int]*Node),
    }

    cache.leastUsed.next = cache.lastUsed
    cache.lastUsed.prev = cache.leastUsed

    return cache
}

func (this *LRUCache) remove(node *Node) {
    prev,next := node.prev,node.next
    prev.next = next
    next.prev = prev
}

func (this *LRUCache) add(node *Node)  {
    prev, next := this.lastUsed.prev, this.lastUsed
    node.prev = prev
    node.next = next
    prev.next = node
    next.prev = node
}


func (this *LRUCache) Get(key int) int {
    if value,exist := this.cache[key] ; exist {
        this.remove(value)
        this.add(value) 
        return value.value
    }
    return -1
}

func (this *LRUCache) Put(key int, value int) {
    if node, ok := this.cache[key]; ok {
        this.remove(node)
        delete(this.cache, key)
    }

     node := &Node{key: key, value: value}
     this.cache[key] = node

     this.add(node)
     if len(this.cache) > this.capacity {
        remove_key := this.leastUsed.next.key
        this.remove(this.leastUsed.next)
        delete(this.cache, remove_key)
     }
}


