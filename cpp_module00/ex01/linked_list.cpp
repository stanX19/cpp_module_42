class Node {
	public:
		void* data;
		Node* next;

		Node(void *_data)
		{
			data = _data;
			next = nullptr;
		}
};
