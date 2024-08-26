int findPindex(supermarket *super,int addIndex,char name[20]){
int index=-1;
for(int i=0;i<super->category[addIndex].productCount;i++){
    if(strcmp(super->category[addIndex].product[i].product_name,name)==0){
        index=i;
        break;
    }
}
return index;
}
