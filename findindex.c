int findIndex(supermarket *super,char name[20]){
int index=-1;
for(int i=0;i<super->catSize;i++){
    if(strcmp(super->category[i].cat_name,name)==0){
        index=i;
        break;
    }
}
return index;
}
