#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <dt-bindings/pinctrl/mt65xx.h>

#include "pinctrl-mtk-mt6595.h"

static const struct mtk_pinctrl_devdata mt6595_pinctrl_data = {
    .pins = mtk_pins_mt6595,
	.npins = ARRAY_SIZE(mtk_pins_mt6595),
};


static int mt6595_pinctrl_probe(struct platform_device *pdev)
{
	pr_warn("mt6595 pinctrl probe\n");
	return mtk_pctrl_init(pdev, &mt6595_pinctrl_data, NULL);
}

static struct of_device_id mt6595_pctrl_match[] = {
	{ .compatible = "mediatek,mt6595-pinctrl", },
    { }
};

static struct platform_driver mtk_pinctrl_driver = {
	.probe = mt6595_pinctrl_probe,
	.driver = {
		.name = "mediatek-mt6595-pinctrl",
		.of_match_table = mt6595_pctrl_match,
	},
};

static int __init mtk_pinctrl_init(void)
{
	return platform_driver_register(&mtk_pinctrl_driver);
}

arch_initcall(mtk_pinctrl_init);
