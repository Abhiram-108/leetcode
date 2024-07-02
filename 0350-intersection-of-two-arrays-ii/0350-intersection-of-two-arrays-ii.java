class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int[] a=new int[1001];
        int[] result=new int[1001];
        for(int it:nums1){
            a[it]++;
        }
        int j=0;
        for(int it:nums2){
            if(a[it]>0){
                result[j++]=it;
                a[it]--;
            }
        }
        
        
        //retruns only filled portion of arrays
        return Arrays.copyOfRange(result,0,j);
        
    }
}