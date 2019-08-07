# arp_spoof

### Network Infrastructure
![infrastructure](https://user-images.githubusercontent.com/13353498/62630231-7ceb2280-b969-11e9-9e86-4a6f4ffd45e1.PNG)

### 공격 Flow

#### 1. BroadCast를 날려 Sender의 MAC 주소 확보

![seq-1](https://user-images.githubusercontent.com/13353498/62630232-7ceb2280-b969-11e9-8678-b6bc6a8b2ad2.PNG)


#### 2. Sender가 자신의 MAC 주소 Reply

![seq-2](https://user-images.githubusercontent.com/13353498/62630220-7b215f00-b969-11e9-8ba7-1a768641aed4.PNG)

#### 3.  Attacker가 감염된 ARP Reply 전송 -> Sender이 ARP Table 오염됨

![seq-3](https://user-images.githubusercontent.com/13353498/62630221-7b215f00-b969-11e9-8742-80e350b448ef.PNG)

#### 4.  Sender가 오염된 ARP Table에 따라 모든 통신 내용을 Attacker에게 보냄 

![seq-4](https://user-images.githubusercontent.com/13353498/62630222-7bb9f580-b969-11e9-93e6-e08214fa0133.PNG)

#### 5. Attacker는 Sender가 보낸 패킷에서 src mac과 checksum만 바꿔서 Target에게 Relay해줌

![seq-5](https://user-images.githubusercontent.com/13353498/62630223-7c528c00-b969-11e9-8acb-98134e63b1df.PNG)

#### 6. Target을 통해 Attacker에게 들어오는 응답들은 src ip와 checksum을 변경해서 Sender에게 Relay 해줌

![seq-6](https://user-images.githubusercontent.com/13353498/62643562-2e4a8200-b983-11e9-8802-f370655db902.PNG)

#### 7. Sender가 unicast로 ARP 확인을 위해 ARP Request를 날릴경우 Attack에게 오므로 바로 감염된 ARP Reply 패킷을 unicast로 Sender에게 재전송-> 오염된 ARP Table 유지

![seq-7](https://user-images.githubusercontent.com/13353498/62643563-2e4a8200-b983-11e9-8708-3535f72adf71.PNG)

#### 8. Target의 ARP Table 제한시간이 다될경우 Sender에게 ARP Request를 날릴 경우 Sender의 ARP Table이 복구되고 공격은 실패(Attacker는 이것은 탐지 못함)

![seq-8](https://user-images.githubusercontent.com/13353498/62643565-2ee31880-b983-11e9-8098-fd9a1502b295.PNG)

#### 9. Attacker는 양쪽에게 모두 ARP 감염 패킷을 주기적으로 보내 ARP Table이 오염된 상태를 유지하게 해야함

![seq-9](https://user-images.githubusercontent.com/13353498/62643566-2ee31880-b983-11e9-9a61-f9ff87fb7b94.PNG)

#### 10. 공격 중지시 양쪽 모두에게 정상 ARP Reply 패킷을 보내서 오염된 ARP Table을 복구한후 공격종료(네트워크 정상화)

![seq-10](https://user-images.githubusercontent.com/13353498/62643567-2ee31880-b983-11e9-9091-13d456f119ff.PNG)
