class ListNode {
    public int key;
    public int value;
    public ListNode next;
    public ListNode prev;

    public ListNode(int key, int value) {
        this.key = key;
        this.value = value;
    }

    public ListNode(int key, int value, ListNode next, ListNode prev) {
        this.key = key;
        this.value = value;
        this.next = next;
        this.prev = prev;
    }
}


class LRUCache {
    private final int capacity;
    private final Map<Integer, ListNode> keyValues = new HashMap<>();
    private ListNode head = new ListNode(-1, -1);
    private ListNode tail = new ListNode(-1, -1);

    private class ListNode {
        public int key;
        public int value;
        public ListNode next;
        public ListNode prev;

        public ListNode(int key, int value) {
            this.key = key;
            this.value = value;
        }

        public ListNode(int key, int value, ListNode next, ListNode prev) {
            this.key = key;
            this.value = value;
            this.next = next;
            this.prev = prev;
        }
    }

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    private void insertNode(ListNode node) {
        var prev = this.tail.prev;
        prev.next = node;
        node.prev = prev;
        node.next = this.tail;
        this.tail.prev = node;
    }

    private void deleteNode (ListNode node) {
        var prev = node.prev;
        var next = node.next;
        prev.next = next;
        next.prev = prev;
    }

    public int get(int key) {
        if (!this.keyValues.containsKey(key)) {
            return -1;
        }
        var node = this.keyValues.get(key);
        this.deleteNode(node);
        this.insertNode(node);
        return node.value;
    }

    public void put(int key, int value) {
        if (this.keyValues.containsKey(key)) {
            var nodeToDelete = this.keyValues.get(key);
            this.deleteNode(nodeToDelete);
        }

        var node = new ListNode(key, value);
        this.keyValues.put(key, node);
        if (this.keyValues.size() > capacity) {
           var nodeToDelete = this.head.next;
           this.keyValues.remove(nodeToDelete.key);
           this.deleteNode(nodeToDelete);
        }
        this.insertNode(node);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

