#include <stdio.h>
#include <stdlib.h>

#define BOY  'b'
#define GIRL 'g'

/*int main(void) {
    int n, i, sum;
    char gender;
    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++)
       scanf("%d", &arr[i]);
    scanf(" %c", &gender);

    sum = 0;
    i = (gender == BOY) ? 0 : 1;
    for (; i < n; i+=2) {
        sum += arr[i];
    }

    printf("%d\n", sum);
    return 0;
}*/

int marks_summation(int* marks, int number_of_students, char gender) {
    int i = (gender == BOY) ? 0 : 1;
    int sum = 0;

    for (; i < number_of_students; i+=2) {
        sum += marks[i];
    }
    return sum;
}

int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}