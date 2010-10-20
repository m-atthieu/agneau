#ifndef __IMAGEVIEWER_HPP__
#define __IMAGEVIEWER_HPP__

#include <QtGui>

#include "BlackAndWhiteConverter.hpp"
#include "ColorSlider.hpp"
#include "RGBColorSliders.hpp"
#include "SixColorSliders.hpp"

namespace Agneau {
  /**
   *
   */
  class ImageViewer: public QWidget
  {
    Q_OBJECT
    
    public:
    /**
     *
     */
    ImageViewer();
    /**
     *
     */
    void open(QString);
                      
  private slots:
    /**
     *
     */
    void setChannel(QString channel, int value);
    
  private:
    /**
     *
     */
    QLabel* imageLabel;
    /**
     *
     */
    QImage* originalImage;
    /**
     *
     */
    RGBColorSliders* colorSliders;
    /**
     *
     */
    BlackAndWhiteConverter* bwConverter;
    /**
     *
     */
    void updateBlackAndWhiteImage();
  };
  
};
#endif /* __IMAGEVIEWER_HPP__ */
