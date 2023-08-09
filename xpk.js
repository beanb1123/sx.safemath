const Antenna = require('iotex-antenna');

(async () => {
  const antenna = new Antenna("https://babel-api.mainnet.iotex.io");

  // recover the whole wallet from a single private key
  const wallet = antenna.iotx.accounts.privateKeyToAccount(
    "69805ee813eadffa8fae53d0e6063e5fbf6a6e0fb9e90f6eaad7bc67f3d6c4bd"
  );

  // get the balance, nonce, number of actions, pendingNonce of the account
  const accountDetails = await antenna.iotx.getAccount({
    address: wallet.address
  });
  console.log(accountDetails);
})();
