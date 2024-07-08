

//Ex: arr1: [3, 5, 7, 8]
//    arr2: [1, 4, 6, 9]
//    ans: [1, 3, 4, 5, 6, 7, 8, 9]

//Brute force: combine both lists and call sort() function. However, time complexity is O(n * logn(n)) due to runtime of sort() function

vector<int> combine(vector<int>& arr1, vector<int>& arr2) { //returrn type is arr1 and arr2 combined in ascending order. arr1 and arr2 are already sorted
    vector<int> = ans; //declaring empty array
    i = 0; //pointer for arr1 and arr2 start at the beginning 
    j = 0; 
    while (i < arr1.length() && j < arr2.length()){ 
        if (arr[i] < arr[j]){ //this is fine to implement since both arrays are already sorted
            ans.push_back(arr[i]);
            i++;
        } else{
            ans.push_back(arr[j]);
            j++;
        }
    }

    //after while loop, one of these arrays will be exhausted but the other one will not be. we need to iterate both lists until all elements from both lists are included in ans
    while (i < arr1.size()){
        ans.push_back(arr1[i]);
        i++;
    }

    while (j < arr1.size()){
        ans.push_back(arr1[j]);
        j++;
    }

    return ans;

}

//space complexity: O(1)
//time complecity: O(n)