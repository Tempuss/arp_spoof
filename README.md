# arp_spoof

### Network Infrastructure
![infrastructure](https://user-images.githubusercontent.com/13353498/62630231-7ceb2280-b969-11e9-9e86-4a6f4ffd45e1.PNG)

### 공격 Flow

1. BroadCast를 날려 Sender의 MAC 주소 확보

![seq-1](https://user-images.githubusercontent.com/13353498/62630232-7ceb2280-b969-11e9-8678-b6bc6a8b2ad2.PNG)


2. Sender가 자신의 MAC 주소 Reply

![seq-2](https://user-images.githubusercontent.com/13353498/62630220-7b215f00-b969-11e9-8ba7-1a768641aed4.PNG)

3.  Attacker가 감염된 ARP Reply 전송 -> Sender이 ARP Table 오염됨

![seq-3](https://user-images.githubusercontent.com/13353498/62630221-7b215f00-b969-11e9-8742-80e350b448ef.PNG)

4.  Sender가 오염된 ARP Table에 따라 모든 통신 내용을 Attacker에게 보냄 

![seq-4](https://user-images.githubusercontent.com/13353498/62630222-7bb9f580-b969-11e9-93e6-e08214fa0133.PNG)

5. Attacker는 Sender가 보낸 패킷에서 src mac과 checksum만 바꿔서 Target에게 Relay해줌

![seq-5](https://user-images.githubusercontent.com/13353498/62630223-7c528c00-b969-11e9-8acb-98134e63b1df.PNG)

6. Sender가 unicast로 ARP 확인을 위해 ARP Request를 날릴경우 Attack에게 오므로 바로 감염된 ARP Reply 패킷을 unicast로 Sender에게 재전송-> 오염된 ARP Table 유지

![seq-6](https://user-images.githubusercontent.com/13353498/62630226-7c528c00-b969-11e9-8a74-8d84eb68ca78.PNG)

7. Target의 ARP Table 제한시간이 다될경우 Sender에게 ARP Request를 날릴 경우 Sender의 ARP Table이 복구되고 공격은 실패(Attacker는 이것은 탐지 못함)

![seq-7](https://user-images.githubusercontent.com/13353498/62630974-ea4b8300-b96a-11e9-9ebc-43e5dddb751f.PNG)

8. Attacker는 양쪽에게 모두 ARP 감염 패킷을 주기적으로 보내 ARP Table이 오염된 상태를 유지하게 해야함

![seq-8](https://user-images.githubusercontent.com/13353498/62630229-7c528c00-b969-11e9-93e2-8ff0700b4302.PNG)

9. 공격 중지시 양쪽 모두에게 정상 ARP Reply 패킷을 보내서 오염된 ARP Table을 복구한후 공격종료(네트워크 정상화)

![seq-9](https://user-images.githubusercontent.com/13353498/62630230-7ceb2280-b969-11e9-803d-a16daebbd9b5.PNG)

