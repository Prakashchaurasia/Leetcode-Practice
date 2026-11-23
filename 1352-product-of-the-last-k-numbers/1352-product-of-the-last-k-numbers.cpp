class ProductOfNumbers {
public:
    vector<int> pre;
    ProductOfNumbers() {
        pre.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            pre.clear();
            pre.push_back(1);
        }
        else pre.push_back(pre.back()*num);
    }
    
    int getProduct(int k) {
        int x=pre.size();
        if(k>=x) return 0;
        return pre[x-1] / pre[x-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */