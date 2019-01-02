#define WEBVIEW_IMPLEMENTATION
#include "webview.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#define PATH_MAX 4096
struct webview counter = {
    .title = "Counter",
    .width = 600,
    .height = 250,
    .debug = 1,
    .resizable = 1,
};

void open_url(struct webview *w, const char *website_url) {
  webview("", website_url, 800, 600, 1);
}

int main() {
  char cwd[PATH_MAX];
  char path[PATH_MAX] = "file://";
  
  getcwd(cwd, sizeof(cwd)); 
  strcat(path, cwd);
  strcat(path, "/app.html"); // concatenated path ends up being something like "file:///home/username/directory/c-webview-example/app.html"

  counter.url = path;
  
  printf("%s", path);
  webview_init(&counter);
  counter.external_invoke_cb = open_url; //open_url is the name of the function invoked from JS
  while (webview_loop(&counter, 1) == 0); // starts rendering the front-end
  return 0;
}