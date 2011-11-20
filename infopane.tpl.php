<?php
/*
 * Default template for pathinfo.
 * 
 * Available variables:
 * 
 */
//dpm($variables, 'theme function variables');
//dpm(get_defined_vars(), 'theme_function');
//dpm($pathinfo, 'pathinfo');



//dpm($variables['pathinfo'], 'theme_function');
/*
foreach($variables['pathinfo']['menu'] as $key=>$value) {
  $menu_items[] = t('%label: @value', array('%label' => $key, '@value' => $value));
}
foreach($variables['pathinfo']['module_info'] as $key=>$value) {
  $module_items = t('%label: @value', array('%label' => $key, '@value' => $value));
}
 */

?>
<div id="pathinfo-infopane">
  <h2>Path: <?php echo $pathinfo['menu']['path']?></h2>
  <?php
    echo theme('module_info', current($pathinfo['module_info']));
  ?>
  <pre>
  <?php// print_r($pathinfo); ?>
  </pre>
  <?php
    //echo theme('item_list', $menu_items);
    //echo theme('item_list', $module_items);
  ?>
</div>