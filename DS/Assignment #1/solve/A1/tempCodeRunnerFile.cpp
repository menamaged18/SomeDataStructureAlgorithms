    for (size_t i = 1; i < size; i++){
        int x = arr[i];
        int j = i - 1;
        while (arr[j] > x && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }