class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k

        tempQ = [-num for num in nums]
        heapq.heapify(tempQ)

        self.minHeap = []
        counter = 0

        while tempQ and counter < k:
            a = heapq.heappop(tempQ)  
            heapq.heappush(self.minHeap, -a)
            counter += 1

    def add(self, val: int) -> int:

        heapq.heappush(self.minHeap, val)
        if len(self.minHeap) > self.k:
            heapq.heappop(self.minHeap)

        return self.minHeap[0]
