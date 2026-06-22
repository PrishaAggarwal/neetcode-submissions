class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
        int i=0;
        int n=nums.size();
        vector<int> sums(n);
        int arr=0; //number of subarray
        int j=0;
        int sum=0;
        for(i=0;i<n;i++){
            if(i==0)
                sums[0]=nums[0];
            else
                sums[i]=sums[i-1]+nums[i];
        }
        sums.insert(sums.begin(), 0);
        for(j=n;j>=0;j--){
            for(i=j-1;i>=0;i--){
                sum=sums[j]-sums[i];
                if(sum==k)
                    arr++;
            }
        }
        return arr;
        */




        //LOGIC 2 with linear time complexity
        int i=0;
        int n=nums.size();
        int arr=0; //count of arry
        int sum=0;
        unordered_map<int,int>pre_sum; 
        pre_sum[0]=1;
        int remains=0;
        while(i<n){
            sum += nums[i]; //this is actully sum of array we are lookign at
            remains=sum-k; //this the prefix we have to remove to get sum of present array equal to k
            if(pre_sum.find(remains) != pre_sum.end()){
                //we are checking if we have the sum..sum basically depicts the number we need to make the array sum equal to k
                //agar voh particular number jo nhi then we add the prefix

                //aab tak maine calculate kr liya ki at prefix sum 0 kitni subarrays ban skti hai...iska mtlb hai that oske phele wale arrays nikalde of sum 0 but then also present subarray ka sum is k
                //lets say 2..ek toh ho gyi when we empty subarray that puri present subarray
                //iske alava ek aur subarray remove krke jiska sum 0 hai...osko remove krke present subarray ka sum k ban jayega
                //toh jo number of arrays phele 0 thi..osko increment by
                arr+=pre_sum[remains];
                pre_sum[sum]++;
                i++;
            }
            else{
                pre_sum[sum]++; //jo sum aaya voh prefix mein nhi hia toh hum oss prefix wale sum ko store kr rhe taki we know what there 
                //hume pta lg jayega that kitne prefix hai jinka sum same same hai
                i++;
            }
        }
        return arr;
    }
};