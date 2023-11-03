#include <stdio.h>
#define MONTHS 12

const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void min_max_avg(float sales[MONTHS]) {
  float min = sales[0], max = sales[0], sum = 0.0;
  int min_month = 0, max_month = 0;
  for (int i = 0; i < MONTHS; i++) {
    if (sales[i] < min) {
      min = sales[i];
      min_month = i;
    }
    if (sales[i] > max) {
      max = sales[i];
      max_month = i;
    }
    sum += sales[i];
  }
  printf("Minimum sales: $%.2f (%s)\n", min, months[min_month]);
  printf("Maximum sales: $%.2f (%s)\n", max, months[max_month]);
  printf("Average sales: $%.2f\n", sum / MONTHS);
   printf("\n");
}

void six_month_avg(float sales[MONTHS]) {
  printf("Six-Month Moving Average Report:\n");
  for (int i = 0; i < MONTHS - 5; i++) {
    float avg = (sales[i] + sales[i + 1] + sales[i + 2] + sales[i + 3] + sales[i + 4] + sales[i + 5]) / 6.0;
    printf("%-8s -  %-12s $%7.2f\n", months[i], months[i + 5], avg);
  }
}

void print_sales_descending(float sales[MONTHS]) {
  float sorted_sales[MONTHS];
  int sorted_months[MONTHS];
  for (int i = 0; i < MONTHS; i++) {
    sorted_sales[i] = sales[i];
    sorted_months[i] = i;
  }
  for (int i = 0; i < MONTHS; i++) {
    for (int j = i + 1; j < MONTHS; j++) {
      if (sorted_sales[i] < sorted_sales[j]) {
        float temp = sorted_sales[i];
        sorted_sales[i] = sorted_sales[j];
        sorted_sales[j] = temp;
        int temp_month = sorted_months[i];
        sorted_months[i] = sorted_months[j];
        sorted_months[j] = temp_month;
      }
    }
  }
  int width = 10; // set the width for month names
  printf("Sales Report (Highest to Lowest):\n");
  printf("Month      Sales\n");
  for (int i = 0; i < MONTHS; i++) {
    printf("%-*s $%7.2f\n", width, months[sorted_months[i]], sorted_sales[i]);
  }
   printf("\n");
}


int main() {
  float sales[MONTHS] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
  print_sales_descending(sales);
  min_max_avg(sales);
  six_month_avg(sales);
  return 0;
}
