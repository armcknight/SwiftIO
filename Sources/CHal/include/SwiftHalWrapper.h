

void swiftHal_msSleep(int t);
void swiftHal_usWait(int t);
long long swiftHal_getUpTimeInMs(void);
unsigned int swiftHal_getClockCycle(void);
unsigned int swiftHal_computeNanoseconds(unsigned int);




typedef struct {
	void *classPtr;
	void (*callback)(void *);
} CallbackWrapper;

typedef struct {
	void *ptr;
	unsigned char idNumber;
	unsigned char direction;
	unsigned char inputMode;
	unsigned char outputMode;
	unsigned char interruptMode;
	unsigned char interruptState;
} DigitalIOObject;

int swiftHal_gpioInit(DigitalIOObject *);
int swiftHal_gpioDeinit(DigitalIOObject *);
int swiftHal_gpioConfig(DigitalIOObject *);
int swiftHal_gpioInterruptConfig(DigitalIOObject *);
int swiftHal_gpioWrite(DigitalIOObject *, int);
int swiftHal_gpioRead(DigitalIOObject *);
int swiftHal_gpioAddCallback(DigitalIOObject *);
int swiftHal_gpioRemoveCallback(DigitalIOObject *);
int swiftHal_gpioEnableCallback(DigitalIOObject *obj);
int swiftHal_gpioDisableCallback(DigitalIOObject *obj);
int swiftHal_gpioAddSwiftMember(DigitalIOObject *obj, void *classPtr, void (*function)(void *));




typedef struct {
	void *ptr;
	unsigned char idNumber;
	int speed;
} I2CObject;

int swiftHal_i2cInit(I2CObject *obj);
int swiftHal_i2cDeinit(I2CObject *obj);
int swiftHal_i2cConfig(I2CObject *obj);
int swiftHal_i2cWrite(I2CObject *obj, unsigned char address, const unsigned char *buf, int length);
int swiftHal_i2cRead(I2CObject *obj, unsigned char address, unsigned char *buf, int length);
int swiftHal_i2cWriteRead(I2CObject *obj, unsigned char address, const unsigned char *wBuf, int wLen, unsigned char *rBuf, int rLen);




typedef struct {
	void *ptr;
	unsigned char idNumber;
	int speed;
} SPIObject;

int swiftHal_spiInit(SPIObject *obj);
int swiftHal_spiDeinit(SPIObject *obj);
int swiftHal_spiConfig(SPIObject *obj);
int swiftHal_spiWrite(SPIObject *obj, const unsigned char *buf, int length);
int swiftHal_spiRead(SPIObject *obj, unsigned char *buf, int length);





typedef struct {
	void *ptr;
	unsigned char idNumber;
	unsigned char parity;
	unsigned char stopBits;
	unsigned char dataBits;
	int baudRate;
	int readBufferLength;
} UARTObject;

int swiftHal_uartInit(UARTObject *obj);
int swiftHal_uartDeinit(UARTObject *obj);
int swiftHal_uartConfig(UARTObject *obj);
int swiftHal_uartWriteChar(UARTObject *obj, unsigned char byte);
int swiftHal_uartWrite(UARTObject *obj, const unsigned char *buf, int length);
unsigned char swiftHal_uartReadChar(UARTObject *obj);
int swiftHal_uartRead(UARTObject *obj, unsigned char *buf, int length);
int swiftHal_uartCount(UARTObject *obj);
int swiftHal_uartClearBuffer(UARTObject *obj);




typedef struct {
	void *ptr;
	CallbackWrapper callbackWrapper;
	unsigned char timerType;
	int	period;
} TimerObject;

int swiftHal_timerInit(TimerObject *obj);
int swiftHal_timerDeinit(TimerObject *obj);
int swiftHal_timerStart(TimerObject *obj);
int swiftHal_timerStop(TimerObject *obj);
int swiftHal_timerCount(TimerObject *obj);
int swiftHal_timerAddSwiftMember(TimerObject *obj, void *classPtr, void (*function)(void *));




typedef struct {
	void *ptr;
	unsigned char idNumber;
	unsigned int period;
	unsigned int pulse;
	unsigned int countPerSecond;
} PWMOutObject;

int swiftHal_PWMOutConfig(PWMOutObject *obj);
int swiftHal_PWMOutInit(PWMOutObject *obj);
int swiftHal_PWMOutDeinit(PWMOutObject *obj);




typedef struct {
	void *ptr;
	unsigned char idNumber;
	int resolution;
	float refVoltage;
} AnalogInObject;

int swiftHal_AnalogInInit(AnalogInObject *obj);
int swiftHal_AnalogInDeinit(AnalogInObject *obj);
int swiftHal_AnalogInRead(AnalogInObject *obj);




typedef struct {
	int maxCountValue;
} CounterInfo;

typedef struct {
	void *ptr;
	CounterInfo info;
	unsigned char idNumber;
	unsigned char mode;
} CounterObject;

int swiftHal_CounterInit(CounterObject *obj);
int swiftHal_CounterDeinit(CounterObject *obj);
int swiftHal_CounterRead(CounterObject *obj);
void swiftHal_CounterStart(CounterObject *obj);
void swiftHal_CounterStop(CounterObject *obj);
void swiftHal_CounterClear(CounterObject *obj);