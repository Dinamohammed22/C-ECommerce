
void display(supermarket * super){
      for(int i=0;i<super->catSize;i++){
            printf("Category : %s\n",super->category[i].cat_name);
            for(int j=0;j<super->category[i].productCount;j++){
            printf("          Product : %s  | Quantity : %i   | Price : %i \n",super->category[i].product[j].product_name,super->category[i].product[j].quantity,super->category[i].product[j].price );

            }
      }
}
