#include "post.h"

int main(){

    arrayPost_t post = arrayPost_create();

    addPost(post, 0, "Cola on the Politecknichna Streen is closed");
    addPost(post, 1, "NADYA ZALILA MEMASIKI NA KPICHAN");
    addPost(post, 2, "CATS ^^");
    printf("%s\n",getPostByIndex(post,0));
    printf("%s\n",getPostByIndex(post,1));
    printf("%s\n",getPostByIndex(post,2));
    printf("%i\n",getPostAmount(post));

    randomRepostAmount(post);

    printf("%i\n",getPostIndex(post));
    printf("%s\n",getPostByIndex(post,0));
    printf("%s\n\n",getPostByIndex(post,1));

  return 0;
}
