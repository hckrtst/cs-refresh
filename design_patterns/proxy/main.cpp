#include <iostream>
using namespace std;

class IViewer {
public:
   virtual void Show() = 0;
};

class ImageView: IViewer {
public:
   ImageView() {
      cout << "ImageView()" << endl;
   }
   void Show() {
      cout << "Now showing the full image" << endl;
   }
};

// the proxy class
class ImagePreview : IViewer {
public:
   ImageView imageView;
   ImagePreview() {
      cout << "ImagePreview() created to show preview only" << endl;
   }
   void Show() {
      imageView.Show();
   }
};
int main() {
   ImagePreview im;
   im.Show();

   return 0;
}