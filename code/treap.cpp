// Cartesian tree (treap)
// Compute sum (here) of a range, and can reverse a range
// COMPLEXITY on average : construction O(nlog n)?, operations O(log n), lazy reversal
// all ranges are 1-based
struct Node {
  int y, sz;
  long long v, sm;
  bool rev;
  struct Node *l, *r;
  Node(long long v) : v(v) {
    y = rand();
    sm = v;
    rev = false;
    sz = 1;
    l = r = NULL;
  }
};
typedef struct Node Node;
int size(Node *n) {
  return n != NULL ? n->sz : 0;
}
long long sum(Node *n) {
  return n != NULL ? n->sm : 0;
}
void update(Node *n) {
  if(n != NULL) {
    n->sm = n->v + sum(n->l) + sum(n->r);
    n->sz = 1 + size(n->l) + size(n->r);
  }
}
void push(Node *n) { // push reverse flag
  if(n != NULL && n->rev) {
    swap(n->l, n->r);
    n->rev = false;
    if(n->l != NULL)
      n->l->rev ^= true;
    if(n->r != NULL)
      n->r->rev ^= true;
  }
}
void merge(Node* &n, Node *l, Node *r) {
  push(l); push(r);
  if(l == NULL) {
    n = r; return;
  }
  if(r == NULL) {
    n = l; return;
  }
  if(l->y > r->y) {
    merge(l->r, l->r, r);
    n = l;
  }
  else {
    merge(r->l, l, r->l);
    n = r;
  }
  update(n);
}
// x stays in r
void split(Node *n, Node* &l, Node* &r, int x, int add = 0) {
  push(n);
  if(n == NULL) {
    l = r = NULL; return;
  }
  int key = size(n->l) + 1 + add;
  if(x <= key) {
    split(n->l, l, n->l, x, add);
    r = n;
  }
  else {
    split(n->r, n->r, r, x, key);
    l = n;
  }
  update(n);
}
// reverse [l, r] (1-based)
void reverse(Node* &n, int l, int r) {
  Node *a, *b;
  split(n, n, a, l, 0);
  split(a, a, b, r - l + 2, 0);
  a->rev ^= true;
  merge(n, n, a);
  merge(n, n, b);
}
// query sum of [l, r] (1-based)
long long query(Node* &n, int l, int r) {
  long long ans;
  Node *a, *b;
  split(n, n, a, l, 0);
  split(a, a, b, r - l + 2, 0);
  ans = sum(a);
  merge(n, n, a);
  merge(n, n, b);
  return ans;
}
// insert value v at position p (if p <= size, at the end if p > size)
void insert(Node* &n, int p, long long v) {
  Node *a;
  split(n, n, a, p);
  merge(n, n, new Node(v));
  merge(n, n, a);
}
// delete element at position p (if any)
void del(Node* &n, int p) {
  Node *a, *b;
  split(n, n, a, p);
  split(a, a, b, 2);
  merge(n, n, b);
  if(a)
    delete a;
}

// TEST
int main() {
  int values[] = {6,5,4,1,2,3}, n = sizeof(values)/sizeof(int);
  Node *r = NULL;
  for(int i = 0; i < n; i++)
    merge(r, r, new Node(values[i]));
  assert(query(r, 1, 6) == 21);
  assert(query(r, 1, 3) == 15);
  assert(query(r, 3, 4) == 5);
  reverse(r, 1, 3); // 4 5 6 1 2 3
  assert(query(r, 1, 3) == 15);
  assert(query(r, 3, 4) == 7);
  reverse(r, 1, 6); // 3 2 1 6 5 4
  assert(query(r, 1, 6) == 21);
  assert(query(r, 5, 6) == 9);
  insert(r, 2, 8); // 3 8 2 1 6 5 4
  assert(query(r, 2, 2) == 8);
  assert(query(r, 1, 3) == 13);
  insert(r, 3, 2); // 3 8 2 2 1 6 5 4
  assert(query(r, 1, 4) == 15);
  del(r, 3); // 3 8 2 1 6 5 4
  assert(query(r, 2, 2) == 8);
  assert(query(r, 1, 3) == 13);
  del(r, 1); // 8 2 1 6 5 4
  assert(query(r, 2, 5) == 14);
  del(r, 2);
  del(r, 3);
  del(r, 2);
  del(r, 2);
  del(r, 1);
  del(r, 1); //
  assert(query(r, 1, 5) == 0);

  r = NULL;
  insert(r, 1, 10); // 10
  insert(r, 1, 2); // 2 10
  assert(query(r, 1, 1) == 2);
  assert(query(r, 1, 2) == 12);
  del(r, 2);
  del(r, 1); //

  r = NULL;
  insert(r, 1, 3); // 3
  assert(query(r, 1, 1) == 3);
  insert(r, 2, 2); // 3 2
  assert(query(r, 1, 2) == 5);
  assert(query(r, 2, 2) == 2);
  return 0;
}
