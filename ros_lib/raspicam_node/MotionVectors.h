#ifndef _ROS_raspicam_node_MotionVectors_h
#define _ROS_raspicam_node_MotionVectors_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace raspicam_node
{

  class MotionVectors : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t mbx;
      uint8_t mby;
      uint8_t x_length;
      int8_t st_x;
      int8_t * x;
      uint8_t y_length;
      int8_t st_y;
      int8_t * y;
      uint8_t sad_length;
      uint16_t st_sad;
      uint16_t * sad;

    MotionVectors():
      header(),
      mbx(0),
      mby(0),
      x_length(0), x(NULL),
      y_length(0), y(NULL),
      sad_length(0), sad(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->mbx >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mbx);
      *(outbuffer + offset + 0) = (this->mby >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mby);
      *(outbuffer + offset++) = x_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < x_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_xi;
      u_xi.real = this->x[i];
      *(outbuffer + offset + 0) = (u_xi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->x[i]);
      }
      *(outbuffer + offset++) = y_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < y_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_yi;
      u_yi.real = this->y[i];
      *(outbuffer + offset + 0) = (u_yi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->y[i]);
      }
      *(outbuffer + offset++) = sad_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sad_length; i++){
      *(outbuffer + offset + 0) = (this->sad[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sad[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sad[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->mbx =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mbx);
      this->mby =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mby);
      uint8_t x_lengthT = *(inbuffer + offset++);
      if(x_lengthT > x_length)
        this->x = (int8_t*)realloc(this->x, x_lengthT * sizeof(int8_t));
      offset += 3;
      x_length = x_lengthT;
      for( uint8_t i = 0; i < x_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_st_x;
      u_st_x.base = 0;
      u_st_x.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_x = u_st_x.real;
      offset += sizeof(this->st_x);
        memcpy( &(this->x[i]), &(this->st_x), sizeof(int8_t));
      }
      uint8_t y_lengthT = *(inbuffer + offset++);
      if(y_lengthT > y_length)
        this->y = (int8_t*)realloc(this->y, y_lengthT * sizeof(int8_t));
      offset += 3;
      y_length = y_lengthT;
      for( uint8_t i = 0; i < y_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_st_y;
      u_st_y.base = 0;
      u_st_y.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_y = u_st_y.real;
      offset += sizeof(this->st_y);
        memcpy( &(this->y[i]), &(this->st_y), sizeof(int8_t));
      }
      uint8_t sad_lengthT = *(inbuffer + offset++);
      if(sad_lengthT > sad_length)
        this->sad = (uint16_t*)realloc(this->sad, sad_lengthT * sizeof(uint16_t));
      offset += 3;
      sad_length = sad_lengthT;
      for( uint8_t i = 0; i < sad_length; i++){
      this->st_sad =  ((uint16_t) (*(inbuffer + offset)));
      this->st_sad |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_sad);
        memcpy( &(this->sad[i]), &(this->st_sad), sizeof(uint16_t));
      }
     return offset;
    }

    const char * getType(){ return "raspicam_node/MotionVectors"; };
    const char * getMD5(){ return "f3b1d1ffbb5afc62c85d36a98f659ddf"; };

  };

}
#endif