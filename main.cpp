#include <QApplication>

#include "ImageViewer.hpp"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  Agneau::ImageViewer imageViewer;
  imageViewer.open(argv[1]);
  imageViewer.show();
  return app.exec();
}
