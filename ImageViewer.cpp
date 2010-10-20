#include "ImageViewer.hpp"

#include <cmath>
#include <iostream>

namespace Agneau {
  ImageViewer::ImageViewer()
  {
    this->imageLabel = new QLabel;
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(this->imageLabel);
    this->colorSliders = new RGBColorSliders;
    layout->addWidget(this->colorSliders);
    this->setLayout(layout);
    this->bwConverter = new BlackAndWhiteConverter;
    /* internal signal connections */
    /* connection des sliders avec la conversion en n&b de l'image */
    QObject::connect(this->colorSliders, SIGNAL(channelChanged(QString, int)), 
                     this, SLOT(setChannel(QString, int)));
  }

  void ImageViewer::open(QString path)
  {
    QImage image(path);
    this->originalImage = new QImage(image);

    /* récupérer la profondeur de l'image */
    int depth = image.depth();
    /* mettre les sliders à la bonne valeur max */
    int max = pow(2, depth);
    this->colorSliders->setMaximum(max);
    /* on convertit en n&b avec un réglage par défaut */
    QImage* bwImage = new QImage(image);
    this->bwConverter->convert(bwImage);
    /* on ajoute l'image en n&b */
    this->imageLabel->setPixmap(QPixmap::fromImage(*bwImage));
  }

  void ImageViewer::setChannel(QString channel, int value)
  {
    //std::cout << channel.toStdString() << "is set to " << value << std::endl;
    /* c'est ici qu'on met à jour l'image en n&b */
  }

  void ImageViewer::updateBlackAndWhiteImage()
  {
    
  }
};
