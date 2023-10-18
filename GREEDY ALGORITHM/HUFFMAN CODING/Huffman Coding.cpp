struct Node {
        int freq;
        char c;
        Node *left, *right;
        Node() {
            freq = 0;
            c = '\0';
            left = right = NULL;
        }
        Node(int v, char ch, Node *l = NULL, Node *r = NULL) {
            freq = v;
            c = ch;
            left = l;
            right = r;
        }
    };
    class comp
    {
        public:
        bool operator()(Node *a, Node *b)
        {
            return a->freq > b->freq;
        }
    };
	public:
	    void preorder(Node* root, vector<string>&res, string yet) {
	        if(root == NULL) return;
	        if(root->c != '$') {
	            res.push_back(yet);
	            return;
	        }
	        preorder(root->left,res,yet+'0');
	        preorder(root->right,res,yet+'1');
	    }
	
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    vector<string>res;
		    priority_queue<Node*, vector<Node*>, comp >pq;
		    
		    for(int i = 0; i < N; i++) {
		        char ch = S[i];
		        int frq = f[i];
		        Node * newNode = new Node(frq,ch);
		        pq.push(newNode);
		    }
		    
		    while(pq.size() > 1) {
		        Node * min1 = pq.top(); pq.pop();
		        Node * min2 = pq.top(); pq.pop();
		        int freqSum = min1->freq + min2->freq;
		        Node * newNode = new Node(freqSum, '$', min1, min2);
		        pq.push(newNode);
		    }
		    
		    preorder(pq.top(), res, "");
		    
		    return res;
		}


