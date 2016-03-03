#include "post.h"
#include <assert.h>

int main(){

    arrayPost_t post = arrayPost_create();

    addPost(post, 3, "Cola on the Politecknichna Streen is closed");
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
