#ifndef _ROS_control_msgs_JointJog_h
#define _ROS_control_msgs_JointJog_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace control_msgs
{

  class JointJog : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t joint_names_length;
      char* st_joint_names;
      char* * joint_names;
      uint8_t displacements_length;
      float st_displacements;
      float * displacements;
      uint8_t velocities_length;
      float st_velocities;
      float * velocities;
      float duration;

    JointJog():
      header(),
      joint_names_length(0), joint_names(NULL),
      displacements_length(0), displacements(NULL),
      velocities_length(0), velocities(NULL),
      duration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = joint_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_names_length; i++){
      uint32_t length_joint_namesi = strlen(this->joint_names[i]);
      memcpy(outbuffer + offset, &length_joint_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_joint_namesi);
      offset += length_joint_namesi;
      }
      *(outbuffer + offset++) = displacements_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < displacements_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->displacements[i]);
      }
      *(outbuffer + offset++) = velocities_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < velocities_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->velocities[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->duration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t joint_names_lengthT = *(inbuffer + offset++);
      if(joint_names_lengthT > joint_names_length)
        this->joint_names = (char**)realloc(this->joint_names, joint_names_lengthT * sizeof(char*));
      offset += 3;
      joint_names_length = joint_names_lengthT;
      for( uint8_t i = 0; i < joint_names_length; i++){
      uint32_t length_st_joint_names;
      memcpy(&length_st_joint_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_joint_names-1]=0;
      this->st_joint_names = (char *)(inbuffer + offset-1);
      offset += length_st_joint_names;
        memcpy( &(this->joint_names[i]), &(this->st_joint_names), sizeof(char*));
      }
      uint8_t displacements_lengthT = *(inbuffer + offset++);
      if(displacements_lengthT > displacements_length)
        this->displacements = (float*)realloc(this->displacements, displacements_lengthT * sizeof(float));
      offset += 3;
      displacements_length = displacements_lengthT;
      for( uint8_t i = 0; i < displacements_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_displacements));
        memcpy( &(this->displacements[i]), &(this->st_displacements), sizeof(float));
      }
      uint8_t velocities_lengthT = *(inbuffer + offset++);
      if(velocities_lengthT > velocities_length)
        this->velocities = (float*)realloc(this->velocities, velocities_lengthT * sizeof(float));
      offset += 3;
      velocities_length = velocities_lengthT;
      for( uint8_t i = 0; i < velocities_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_velocities));
        memcpy( &(this->velocities[i]), &(this->st_velocities), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->duration));
     return offset;
    }

    const char * getType(){ return "control_msgs/JointJog"; };
    const char * getMD5(){ return "1685da700c8c2e1254afc92a5fb89c96"; };

  };

}
#endif