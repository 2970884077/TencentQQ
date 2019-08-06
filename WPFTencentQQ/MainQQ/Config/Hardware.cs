﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MainQQ.Config
{
    class Hardware
    {
        public string DEFAULT_DEVICE_ID_UNIQUENO;
        public string DEFAULT_IMEI;
	    public string DEFAULT_WIFI_MAC;
        public string DEFAULT_DEVICE_ID;
	    public string DEFAULT_IMSI;
	    public string DEFAULT_OS_TYPE;
	    public string DEFAULT_OS_VERSION;
	    public uint DEFAULT_OS_INT_VERSION;
	    public short DEFALUT_NETWORK_INT_TYPE;
	    public string DEFAULT_SIM_OPERATOR_NAME;
	    public string DEFAULT_APN;
	    public string DEFAULT_BRAND;
	    public string DEFAULT_ANDROID_ID;
	    public string DEFAULT_BSSID;
	    public string DEFAULT_SSID;
        public Hardware()
        {
            DEFAULT_DEVICE_ID_UNIQUENO="357747058988888|null";//null可能为DEFAULT_WIFI_MAC,getDeviceId与getMacAddress组成，当GSM getDeviceId返回IMEI，CDMA返回MEID
	        DEFAULT_IMEI="357747058988888";
	        DEFAULT_WIFI_MAC="03:BB:F0:66:8E:84";
	        DEFAULT_DEVICE_ID="063116583635976";//即MEID
	        DEFAULT_IMSI="310260419859463";
	        DEFAULT_OS_TYPE="android";
	        DEFAULT_OS_VERSION="2.3.4";
	        DEFAULT_OS_INT_VERSION=21;//level
	        DEFALUT_NETWORK_INT_TYPE=0x0002;
	        DEFAULT_SIM_OPERATOR_NAME="T-Mobile";
	        DEFAULT_APN="wifi";
	        DEFAULT_BRAND="Lan998";
	        DEFAULT_ANDROID_ID="9043de15babc9d5b";
	        DEFAULT_BSSID="03:BB:F0:66:8E:85";
	        DEFAULT_SSID="BlueStacks";
        }
    }
}
