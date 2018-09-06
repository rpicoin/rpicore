WISPR Core integration/staging repository
=====================================

[![Build Status](https://travis-ci.org/WisprProject/core.svg?branch=master)](https://travis-ci.org/WisprProject/core) [![GitHub version](https://badge.fury.io/gh/WisprProject%2FWISPR.svg)](https://badge.fury.io/gh/WisprProject%2FWISPR)

WISPR is an open source crypto-currency focused on fast private transactions with low transaction fees & environmental footprint.  It utilizes a custom Proof of Stake protocol for securing its network and uses an innovative variable seesaw reward mechanism that dynamically balances 90% of its block reward size between masternodes and staking nodes and 10% dedicated for budget proposals. The goal of WISPR is to achieve a decentralized sustainable crypto currency with near instant full-time private transactions, fair governance and community intelligence.
- Anonymized transactions using the [_Zerocoin Protocol_](http://www.wispr.tech/zwsp).
- Fast transactions featuring guaranteed zero confirmation transactions, we call it _SwiftX_.
- Decentralized blockchain voting utilizing Masternode technology to form a DAO. The blockchain will distribute monthly treasury funds based on successful proposals submitted by the community and voted on by the DAO.

More information at [wispr.tech](http://www.wispr.tech) Visit our ANN thread at [BitcoinTalk](http://www.bitcointalk.org/index.php?topic=1262920)

### Coin Specs
<table>
<tr><td>Algo</td><td>Quark</td></tr>
<tr><td>Block Time</td><td>60 Seconds</td></tr>
<tr><td>Difficulty Retargeting</td><td>Every Block</td></tr>
<tr><td>Max Coin Supply (PoW Phase)</td><td>43,199,500 WSP</td></tr>
<tr><td>Max Coin Supply (PoS Phase)</td><td>Infinite</td></tr>
<tr><td>Premine</td><td>60,000 WSP*</td></tr>
</table>

*60,000 WSP Premine was burned in block [279917](http://www.presstab.pw/phpexplorer/WISPR/block.php?blockhash=206d9cfe859798a0b0898ab00d7300be94de0f5469bb446cecb41c3e173a57e0)

### Reward Distribution

<table>
<th colspan=4>Genesis Block</th>
<tr><th>Block Height</th><th>Reward Amount</th><th>Notes</th></tr>
<tr><td>1</td><td>60,000 WSP</td><td>Initial Pre-mine, burnt in block <a href="http://www.presstab.pw/phpexplorer/WISPR/block.php?blockhash=206d9cfe859798a0b0898ab00d7300be94de0f5469bb446cecb41c3e173a57e0">279917</a></td></tr>
</table>

### PoW Rewards Breakdown

<table>
<th>Block Height</th><th>Masternodes</th><th>Miner</th><th>Budget</th>
<tr><td>2-43200</td><td>20% (50 WSP)</td><td>80% (200 WSP)</td><td>N/A</td></tr>
<tr><td>43201-151200</td><td>20% (50 WSP)</td><td>70% (200 WSP)</td><td>10% (25 WSP)</td></tr>
<tr><td>151201-259200</td><td>45% (22.5 WSP)</td><td>45% (22.5 WSP)</td><td>10% (5 WSP)</td></tr>
</table>

### PoS Rewards Breakdown

<table>
<th>Phase</th><th>Block Height</th><th>Reward</th><th>Masternodes & Stakers</th><th>Budget</th>
<tr><td>Phase 1</td><td>259201-302399</td><td>50 WSP</td><td>90% (45 WSP)</td><td>10% (5 WSP)</td></tr>
<tr><td>Phase 2</td><td>302400-345599</td><td>45 WSP</td><td>90% (40.5 WSP)</td><td>10% (4.5 WSP)</td></tr>
<tr><td>Phase 3</td><td>345600-388799</td><td>40 WSP</td><td>90% (36 WSP)</td><td>10% (4 WSP)</td></tr>
<tr><td>Phase 4</td><td>388800-431999</td><td>35 WSP</td><td>90% (31.5 WSP)</td><td>10% (3.5 WSP)</td></tr>
<tr><td>Phase 5</td><td>432000-475199</td><td>30 WSP</td><td>90% (27 WSP)</td><td>10% (3 WSP)</td></tr>
<tr><td>Phase 6</td><td>475200-518399</td><td>25 WSP</td><td>90% (22.5 WSP)</td><td>10% (2.5 WSP)</td></tr>
<tr><td>Phase 7</td><td>518400-561599</td><td>20 WSP</td><td>90% (18 WSP)</td><td>10% (2 WSP)</td></tr>
<tr><td>Phase 8</td><td>561600-604799</td><td>15 WSP</td><td>90% (13.5 WSP)</td><td>10% (1.5 WSP)</td></tr>
<tr><td>Phase 9</td><td>604800-647999</td><td>10 WSP</td><td>90% (9 WSP)</td><td>10% (1 WSP)</td></tr>
<tr><td>Phase X</td><td>648000-Infinite</td><td>5 WSP</td><td>90% (4.5 WSP)</td><td>10% (0.5 WSP)</td></tr>
</table>
