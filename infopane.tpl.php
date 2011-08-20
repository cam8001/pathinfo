<?php
/*
 * Default template for pathinfo.
 * 
 * Available variables:
 * 
 */
dpm($variables, 'theme function variables');
dpm(get_defined_vars(), 'theme_function');

//dpm($variables['pathinfo'], 'theme_function');

foreach($variables['pathinfo'] as $key=>$value) {
  if ($key == 'module_info') {
    //foreach ($value as $key=>$va)
  } else {
    $items[] = t('%label: @value', array('%label' => $key, '@value' => $value));
  }
}


?>
<div id="pathinfo-infopane">
  <?php
    echo theme('item_list', $items);
  ?>
</div>