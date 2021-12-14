#ifndef _ROS_rosbridge_msgs_ConnectedClients_h
#define _ROS_rosbridge_msgs_ConnectedClients_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosbridge_msgs/ConnectedClient.h"

namespace rosbridge_msgs
{

  class ConnectedClients : public ros::Msg
  {
    public:
      uint8_t clients_length;
      rosbridge_msgs::ConnectedClient st_clients;
      rosbridge_msgs::ConnectedClient * clients;

    ConnectedClients():
      clients_length(0), clients(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = clients_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < clients_length; i++){
      offset += this->clients[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t clients_lengthT = *(inbuffer + offset++);
      if(clients_lengthT > clients_length)
        this->clients = (rosbridge_msgs::ConnectedClient*)realloc(this->clients, clients_lengthT * sizeof(rosbridge_msgs::ConnectedClient));
      offset += 3;
      clients_length = clients_lengthT;
      for( uint8_t i = 0; i < clients_length; i++){
      offset += this->st_clients.deserialize(inbuffer + offset);
        memcpy( &(this->clients[i]), &(this->st_clients), sizeof(rosbridge_msgs::ConnectedClient));
      }
     return offset;
    }

    const char * getType(){ return "rosbridge_msgs/ConnectedClients"; };
    const char * getMD5(){ return "d0d53b0c0aa23aa7e4cf52f49bca4b69"; };

  };

}
#endif