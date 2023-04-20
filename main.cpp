#include <memory>

template <typename T>
class AVLTree {
  public:
    class Node {
      public:
        Node() = default;
        Node(const T& key) : m_key{ key } {}
        ~Node() {
          delete m_left_tree;
          delete m_right_tree;
        }

        const T& key() { return m_key; }
        void set_key(const T& key) { m_key = key; }
        Node* getRightTree() { return m_right_tree; }
        void setRightTree(Node* p) { m_right_tree=p; }
        Node* getLeftTree() { return m_left_tree; }
        void setLeftTree(Node* p) { m_left_tree = p; }

      private:
        T m_key{};
        int m_balance_factor{ 0 };
        Node* m_left_tree{ nullptr };
        Node* m_right_tree{ nullptr };
    };

    AVLTree() = default;
    AVLTree(Node* root) : m_root{ root } {}

    ~AVLTree() {
      delete m_root;
    }

    Node* root() { return m_root; }
    void set_root(Node* root) { m_root = root; }

    friend std::ostream& operator<<(std::ostream& out, const AVLTree& tree) {
      if (!tree.root()) return out;
      out << AVLTree{ tree.root()->getLeftTree() };
      out << AVLTree{ tree.root()->getRightTree() };

      out << tree.root()->key();

      return out;
    }

    static void simple_left_rotation(Node* p) 
    {
      Node* q = p->getRightTree();

      p->setRightTree(q->getLeftTree());
      q->setLeftTree(p);
    }
    static void simple_right_rotation(Node* p) 
    {
      Node* q = p->getLeftTree();

      p->setLeftTreeTree(q->getRightTree());
      q->setRightTree(p);
    }
    static void double_left_rotation(Node* p) 
    {
      Node* q = p->getRightTree();
      Node* r = q->getLeftTree();

      p->setRightTree(r->getLeftTree());
      q->setLeftTreeTree(r->getRightTree());
      r->setLeftTree(p);
      r->setRightTree(q);
    }
    static void double_right_rotation(Node* p) 
    {
      Node* q = p->getLeftTree();
      Node* r = q->getRightTree();

      p->setLeftTree(r->getRightTree());
      q->setRightTree(r->getLeftTree());
      r->setRightTree(p);
      r->setLeftTree(q);
    }

  private:
    Node* m_root{ nullptr };     
};

