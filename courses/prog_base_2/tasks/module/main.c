#include "post.h"

int main(){

    arrayPost_t post = arrayPost_create();

    post_addPost(post, 0, "Cola on the Politecknichna Streen is closed");
    post_addPost(post, 1, "NADYA ZALILA MEMASIKI NA KPICHAN");
    post_addPost(post, 2, "CATS ^^");
    printf("%s\n",post_getPostByIndex(post,0));
    printf("%s\n",post_getPostByIndex(post,1));
    printf("%s\n",post_getPostByIndex(post,2));
    printf("%i\n",post_getPostAmount(post));

    post_randomRepostAmount(post);

    printf("%i\n",post_getPostIndex(post));
    printf("%s\n",post_getPostByIndex(post,0));
    printf("%s\n\n",post_getPostByIndex(post,1));

  return 0;
}
