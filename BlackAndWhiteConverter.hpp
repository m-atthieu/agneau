#ifndef __BLACKANDWHITECONVERTER_HPP__
#define __BLACKANDWHITECONVERTER_HPP__

#include <QtCore>

namespace Agneau
{
	class BlackAndWhiteConverter;
	//typedef void (BlackAndWhiteConverter::*convert_func)(QImage*);
  /**
   * The lightness method : (max(R, G, B) + min(R, G, B)) / 2.
   * The average method simply averages the values: (R + G + B) / 3.
   * The luminosity method : 0.21 R + 0.71 G + 0.07 B
   * (11*R + 16*G + 5*B) /32 is also popular
   */
  class BlackAndWhiteConverter: public QObject
  {
    Q_OBJECT

    public:
    BlackAndWhiteConverter();
    /* it will directly convert the image */
    void convert(QImage* image);

  private:
    //QHash<QString, convert_func>* methods;
    QString method;
    void meanConvert(QImage* image);
    void luminanceConvert(QImage* image);
    void luminosityConvert(QImage* image);
    void channelsMixerConvert(QImage* image);
  };
};

#endif /* __BLACKANDWHITECONVERTER_HPP__ */
