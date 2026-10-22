#include <linux/nfc/pn553_lge_hwadapter.h>

int pn547_get_hw_revision(void)
{
    return 0;
}

unsigned int pn547_get_irq_pin(struct pn547_dev *dev)
{
    return dev->client->irq;
}

int pn547_gpio_to_irq(struct pn547_dev *dev)
{
    return dev->client->irq;
}

void pn547_gpio_enable(struct pn547_dev *pn547_dev)
{
    return;
}

void pn547_shutdown_cb(struct pn547_dev *pn547_dev)
{
    return;
}

#ifdef CONFIG_LGE_NFC_USE_PMIC
void pn547_get_clk_source(struct i2c_client *pn547_client, struct pn547_dev *pn547_dev)
{
    pn547_dev->clk_cont = clk_get(&pn547_client->dev, "cont_clk");
    if (pn547_dev->clk_cont == NULL) {
        pr_err("%s: PN547 could not get cont. clock!\n", __func__);
    }

    pn547_dev->clk_pin = clk_get(&pn547_client->dev, "pin_clk");
    if (pn547_dev->clk_pin == NULL) {
        pr_err("%s: PN547 could not get pin clock!\n", __func__);
    }
    pr_err("%s: xo_cont = %p, xo_pin = %p\n", __func__, pn547_dev->clk_cont, pn547_dev->clk_pin);
}
#endif

void pn547_parse_dt(struct device *dev, struct pn547_dev *pn547_dev)
{
    struct device_node *np = dev->of_node;

    /* irq gpio info */
    pn547_dev->ven_gpio = of_get_named_gpio_flags(np, "nxp,gpio_ven", 0, NULL);
    pn547_dev->firm_gpio = of_get_named_gpio_flags(np, "nxp,gpio_mode", 0, NULL);
    pn547_dev->irq_gpio = of_get_named_gpio_flags(np, "nxp,gpio_irq", 0, NULL);
}
