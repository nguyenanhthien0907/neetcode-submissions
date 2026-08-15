class LinkedList {
   public:
    struct Node {
        int data;
        Node* next;
        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    LinkedList() { head = nullptr; }

    int get(int index) {
        if (index < 0) return -1;

        Node* current = head;
        int i = 0;

        while (current != nullptr) {
            if (i == index) return current->data;

            current = current->next;
            i++;
        }

        return -1;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    bool remove(int index) {
        if (index < 0 || head == nullptr) return false;

        // Remove head
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* current = head;
        int i = 0;

        // Find node BEFORE the target
        while (current->next != nullptr) {
            if (i + 1 == index) {
                Node* temp = current->next;

                current->next = temp->next;

                delete temp;

                return true;
            }

            current = current->next;
            i++;
        }

        return false;
    }

    vector<int> getValues() {
        std::vector<int> values;

        Node* current = head;

        while (current != nullptr) {
            values.push_back(current->data);
            current = current->next;
        }

        return values;
    }
};
