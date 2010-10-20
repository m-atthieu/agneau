#include "BlackAndWhiteConverter.hpp"

namespace Agneau {
  BlackAndWhiteConverter::BlackAndWhiteConverter()
  {
    /*
     * this->methods = new QHash<QString, convert_func>;
     * this->methods->insert(QString("mean"), this->meanConvert);
     * this->methods[QString("luminosity")] = this->luminosityConvert;
     * this->methods[QString("luminance")] = this->luminanceConvert;
     * this->methods[QString("mixer")] = this->channelsMixerConvert; 
     */
	  this->method("mean");
  }

  void BlackAndWhiteConverter::convert(QImage* image)
  {
	  switch(this->method)
	  {
		  case "mean":
			  this->meanConvert(image);
		  	break;
		  case "luminance":
			  this->luminanceConvert(image);
		  	break;
		case "luminosity":
			this->luminosityConvert(image);
			break;
	  }
  }

  void BlackAndWhiteConverter::meanConvert(QImage* image)
  {
  }
  
  void BlackAndWhiteConverter::luminanceConvert(QImage* image)
  {
  }
  
  void BlackAndWhiteConverter::luminosityConvert(QImage* image)
  {
  }
  
  void BlackAndWhiteConverter::channelsMixerConvert(QImage* image)
  {
  }
};
