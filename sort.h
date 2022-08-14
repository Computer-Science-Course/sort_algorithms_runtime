void selectionSort(
	int vector[],
	int vector_length
){
	int min, temp;

	for(int i = 0; i < vector_length - 1; i++){
		min = i;
		for(int j = i+1; j < vector_length; j++){
			if(vector[j] < vector[min]){
				min = j;
			}
		}
		temp = vector[i];
		vector[i] = vector[min];
		vector[min] = temp;
	}
}

void insertionSort(
	int vector[],
	int vector_length
){
	for (int i = 1; i < vector_length; i++) {
    int floor = vector[i];
    int j = i - 1;

	    while (j >= 0 && floor < vector[j]) {
	      vector[j + 1] = vector[j];
	      --j;
	    }
	    vector[j + 1] = floor;
  	}
}

void merge(
    int vector[],
    int start,
    int middle,
    int end
){
	int i, j, k, left_length, right_length;
	left_length = middle - start + 1;
	right_length = end - middle;
	
	int left_side[left_length + 1], right_side[right_length + 1];
	
	for(i = 0; i < left_length; i++){
		left_side[i] = vector[start + i];
	}
	left_side[i] = 1000000;
	
	for(i = 0; i < right_length; i++){
		right_side[i] = vector[middle + i + 1];
	}
	right_side[i] = 1000000;

	
	i = 0, k = 0, j = 0;
	

	for(k = start; k < end + 1; k++){
		if(left_side[i] <= right_side[j]){
			vector[k] = left_side[i];
			i++;

		} else{
			vector[k] = right_side[j];
			j++;
			
		}
	}
}

void mergesort(
    int vector[],
    int start,
    int end
){
	int meio;
	if(start < end){
		meio = (start + end) / 2;
		mergesort(vector, start, meio);
		mergesort(vector, meio+1, end);
		merge(vector, start, meio, end);
	}
}

int partition(
    int vector[],
    int start,
    int end
){
	int pivot, j, i, temp;
	pivot = vector[end];
	i = start-1;
	for(j = start; j < end; j++){
		if(vector[j] <= pivot){
			i++;
			temp = vector[i];
			vector[i] = vector[j];
			vector[j] = temp;
		}
	}
	temp = vector[i+1];
	vector[i+1] = vector[end];
	vector[end] = temp;
	
	return i+1;
}

void quicksort(
    int vector[],
    int start,
    int end
){
	int position = 0;
	if (start < end){
		position = partition(
            vector,
            start,
            end
        );
		quicksort(
            vector,
            start,
            position - 1
        );
		quicksort(
            vector,
            position + 1,
            end
        );
	}
}

