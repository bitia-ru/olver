<?xml version="1.0" encoding="windows-1251" ?> 

<!-- Following stylesheet shall be included into res.xml -->
<!--?xml-stylesheet type="text/xsl" href="reportgen.xsl"?-->

<xsl:stylesheet version="1.1" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:exslt="http://exslt.org/common">
 	<xsl:output method="html"/>

	<xsl:key name="map_names" match="//CoveredStandaloneMark" use="@name"/> <!-- [number(@hits)>0] -->
	<xsl:key name="map_failures" match="//FailureDesc/Property" use="@value"/> 
	
	<xsl:variable name="ids" select="document('ids.xml')"/>
	<xsl:variable name="root" select="/"/>
	
	<xsl:template match="/">
		<html>
		<script>
			function show(id,al)
			{
				el=document.getElementById(id);
				if(el.style.display!='none')
				{
					el.style.display='none';
					al.innerHTML = "+";
				}else{
					el.style.display='';
					al.innerHTML = "&amp;#150;";
				}
				return false;
			}
		</script>
		<style>
			a {text-decoration:none}
		</style>
		<body>
		
		<!-- Unknown reqs (misprints) -->
		<xsl:variable name="n_id">
			<xsl:text>mispr1</xsl:text>
		</xsl:variable>
		<xsl:variable name="misprints">
			<xsl:for-each select="//CoveredStandaloneMark">
				<xsl:variable name="name" select="@name"/>
				<xsl:variable name="name2" select="substring($name,2)"/>
				<xsl:if test="count($ids//req[((@id=$name) or (@id=$name2))and(@id!='')])=0">
					<font color="red">
					<xsl:text>Misprint? </xsl:text>
					<xsl:value-of select="$name"/><br/>
					</font>
				</xsl:if>
			</xsl:for-each>
		</xsl:variable>
		
		<xsl:variable name="mispr_cont">
			<xsl:value-of select="$misprints"/>
		</xsl:variable>
		
		<xsl:if test="$mispr_cont!=''">
			<xsl:call-template name="plus">
				<xsl:with-param name="n_id" select="$n_id"/>
				<xsl:with-param name="roll" select="substring($mispr_cont,0,1)"/>
			</xsl:call-template>
			<b><xsl:text>Misprints</xsl:text></b>
			<p id="mispr1" style="display:none">
				<xsl:copy-of select="$misprints"/>
			</p>
		</xsl:if>
		
		<xsl:variable name="sub"> <!-- subtree with funcs-->
			<xsl:for-each select="$ids/src/group">
				<xsl:call-template name="group_pre"/>
			</xsl:for-each>				
		</xsl:variable>
		<xsl:variable name="sub_ns" select="exslt:node-set($sub)"/>

		<h4>Summary:<xsl:text>( Total:</xsl:text><xsl:value-of select="sum($sub_ns//func/@total_reqs)"/><xsl:text> / Covered:</xsl:text><xsl:value-of select="sum($sub_ns//func/@cov_reqs)"/><xsl:text> / Failed:</xsl:text><xsl:value-of select="sum($sub_ns//func/@failed_reqs)"/> <xsl:text>)</xsl:text></h4>
		<ul>
		<xsl:for-each select="$sub_ns/group">
			<!-- Tanur: switch off sorting by a number of covered reqs-->
			<!--xsl:sort order="descending" data-type="number" select="@cov_reqs"/-->
			<xsl:sort order="ascending" select="@name"/>
			<li><xsl:apply-templates select="."/></li>
		</xsl:for-each>
		</ul>
		</body></html>
	</xsl:template>

	<xsl:template name="group_pre">
		<xsl:variable name="sub"> <!-- subtree with funcs-->
			<xsl:for-each select="./func">
				<xsl:call-template name="func_pre"/>
			</xsl:for-each>				
		</xsl:variable>
		<xsl:variable name="sub_ns" select="exslt:node-set($sub)"/>

		<xsl:copy>
			<xsl:attribute name="name">
				<xsl:value-of select="@name"/>
			</xsl:attribute>
			<xsl:attribute name="total_reqs">
				<xsl:value-of select="sum($sub_ns/func/@total_reqs)"/>
			</xsl:attribute>
			<xsl:attribute name="cov_reqs">
				<xsl:value-of select="sum($sub_ns/func/@cov_reqs)"/>
			</xsl:attribute>
			<xsl:attribute name="failed_reqs">
				<xsl:value-of select="sum($sub_ns/func/@failed_reqs)"/>
			</xsl:attribute>

			<xsl:copy-of select="$sub_ns"/>	
		</xsl:copy>
	</xsl:template>

	<xsl:template match="group">
		<xsl:variable name="n_id" select="generate-id(.)"/>
		<xsl:variable name="roll" select="false"/>
		<xsl:call-template name="plus">
			<xsl:with-param name="n_id" select="$n_id"/>
			<xsl:with-param name="roll" select="$roll"/>
		</xsl:call-template>
		
		<b><xsl:value-of select="@name"/></b>
		<xsl:text> (</xsl:text>
		<xsl:value-of select="@total_reqs"/>
		<xsl:text> / </xsl:text>
		<xsl:value-of select="@cov_reqs"/>
		<xsl:text> / </xsl:text>
		<xsl:value-of select="@failed_reqs"/>
		<xsl:text>)</xsl:text>
		
		<xsl:element name="ul">
			<xsl:attribute name="id"> <xsl:value-of select="$n_id"/> </xsl:attribute>
			
			<xsl:choose>			
				<xsl:when test="not($roll)">
					<xsl:attribute name="style">
						<xsl:text>display:none</xsl:text>
					</xsl:attribute>
				</xsl:when>
				<xsl:otherwise>
				</xsl:otherwise>
			</xsl:choose>

			<xsl:for-each select="./func">
				<xsl:sort order="descending" data-type="number" select="@cov_reqs"/>
				<xsl:sort order="ascending" select="@name"/>
				<li><xsl:apply-templates select="."/></li>
			</xsl:for-each>
		</xsl:element>
	</xsl:template>

	<xsl:template name="func_pre">
		<xsl:variable name="thisfunc" select="."/>
		
		<xsl:variable name="sub"> <!-- subtree with reqs-->
			<xsl:for-each select="./req">
				<xsl:call-template name="req_pre"/>
			</xsl:for-each>				
		</xsl:variable>
		<xsl:variable name="sub_ns" select="exslt:node-set($sub)/req"/>
	
		<xsl:copy>
			<xsl:attribute name="name">
				<xsl:value-of select="@name"/>
			</xsl:attribute>
			<xsl:attribute name="common">
				<xsl:value-of select="@common"/>
			</xsl:attribute>
			<xsl:attribute name="total_reqs">
				<xsl:value-of select="count($sub_ns[(@is_leave='true') and (@covered!='gray')])"/>
			</xsl:attribute>
			<xsl:attribute name="cov_reqs">
				<xsl:value-of select="count($sub_ns[(@is_leave='true') and (@covered='green' or @covered='yellow')])"/>
			</xsl:attribute>
			<xsl:attribute name="failed_reqs">
				<xsl:value-of select="count($sub_ns[(@is_leave='true') and (@covered='brown')])"/>
			</xsl:attribute>

			<xsl:copy-of select="$sub_ns"/>	
		</xsl:copy>
	</xsl:template>

	<xsl:template match="func"> <!-- TEMPLATE "func" -->
		<xsl:variable name="n_id" select="generate-id(.)"/>
		<xsl:variable name="roll" select="false"/>
		
		<xsl:if test="count(./req)"> 
			<xsl:call-template name="plus">
				<xsl:with-param name="n_id" select="$n_id"/>
				<xsl:with-param name="roll" select="$roll"/>
			</xsl:call-template>
		</xsl:if>

		<xsl:choose>
			<xsl:when test="@cov_reqs=0">
				<font color="#CC0000">
				<xsl:choose>
					<xsl:when test="@common=1">
						<b><i><xsl:value-of select="@name"/></i></b> <!-- funcname (common)-->
					</xsl:when>
					<xsl:otherwise>
						<b><xsl:value-of select="@name"/></b> <!-- funcname -->
					</xsl:otherwise>
				</xsl:choose>
				</font>
			</xsl:when>
			<xsl:when test="@cov_reqs=@total_reqs">
				<font color="#009900">
				<xsl:choose>
					<xsl:when test="@common=1">
						<b><i><xsl:value-of select="@name"/></i></b> <!-- funcname (common)-->
					</xsl:when>
					<xsl:otherwise>
						<b><xsl:value-of select="@name"/></b> <!-- funcname -->
					</xsl:otherwise>
				</xsl:choose>
				</font>
			</xsl:when>
			<xsl:otherwise>
				<xsl:choose>
					<xsl:when test="@common=1">
						<b><i><xsl:value-of select="@name"/></i></b> <!-- funcname (common)-->
					</xsl:when>
					<xsl:otherwise>
						<b><xsl:value-of select="@name"/></b> <!-- funcname -->
					</xsl:otherwise>
				</xsl:choose>
			</xsl:otherwise>
		</xsl:choose>
		
		<xsl:text> (</xsl:text>
		<xsl:value-of select="@total_reqs"/>
		<xsl:text> / </xsl:text>
		<xsl:value-of select="@cov_reqs"/>
		<xsl:text> / </xsl:text>
		<xsl:value-of select="@failed_reqs"/>
		<xsl:text>)</xsl:text>

		<xsl:element name="ul">
			<xsl:attribute name="id"> <xsl:value-of select="$n_id"/> </xsl:attribute>
			
			<xsl:choose>			
				<xsl:when test="not($roll)">
					<xsl:attribute name="style">
						<xsl:text>display:none</xsl:text>
					</xsl:attribute>
				</xsl:when>
				<xsl:otherwise>
				</xsl:otherwise>
			</xsl:choose>
			
			<xsl:for-each select="./req[@dummy!=1]">
				<xsl:sort order="ascending" select="@name"/>
				<li><xsl:apply-templates select="."/></li>
			</xsl:for-each>
		</xsl:element>		

	</xsl:template> <!-- END OF TEMPLATE "func" -->

	<xsl:template name="req_pre"> <!-- TEMPLATE "pre_req" -->
		<xsl:variable name="cid" select="@id"/>
		<xsl:variable name="cid2" select="concat('?',$cid)"/>
		<xsl:variable name="is_app" select="starts-with($cid,'app.') or (@struct=1)"/>

		<xsl:variable name="sub"> <!-- subtree with reqs-->
			<xsl:for-each select="./req">
				<xsl:call-template name="req_pre"/>
			</xsl:for-each>
		</xsl:variable>
		<xsl:variable name="sub_ns" select="exslt:node-set($sub)/req"/>

		<xsl:variable name="gsub"> <!-- subtree with gsubs-->
			<xsl:for-each select="./gsub">
				<xsl:call-template name="gsub_pre"/>
			</xsl:for-each>
		</xsl:variable>
		<xsl:variable name="gsub_ns" select="exslt:node-set($gsub)/gsub"/> <!-- gsub -->

		<xsl:variable name="children_count" select="count($sub_ns)"/>
		<xsl:variable name="children_red" select="count($sub_ns[@covered='red'])"/>
		<xsl:variable name="children_yellow" select="count($sub_ns[@covered='yellow'])"/>
		<xsl:variable name="children_green" select="count($sub_ns[@covered='green'])"/>
		
		<xsl:variable name="gsub_count" select="count($gsub_ns)"/>
		<xsl:variable name="gsub_red" select="count($gsub_ns[@covered='red'])"/>
		<xsl:variable name="gsub_yellow" select="count($gsub_ns[@covered='yellow'])"/>
		<xsl:variable name="gsub_green" select="count($gsub_ns[@covered='green'])"/>
		
		<xsl:copy>
			<xsl:attribute name="covered">
				<xsl:for-each select="$root"> <!-- Dummy foreach -->	
					<xsl:variable name="nod" select="key('map_names',$cid)" />
					<xsl:variable name="nod2" select="key('map_names',$cid2)" />
					<xsl:variable name="nod3" select="key('map_failures',$cid)" />
					<xsl:choose>
						<xsl:when test="$is_app">
							<xsl:text>gray</xsl:text>
						</xsl:when>
						<xsl:when test="count($nod3)!=0">
							<xsl:text>brown</xsl:text>
						</xsl:when>
						<xsl:when test="count($nod)!=0">
							<xsl:text>green</xsl:text>
						</xsl:when>
						<xsl:when test="count($nod2)!=0">
							<xsl:text>yellow</xsl:text>
						</xsl:when>
						<xsl:when test="($children_red=0) and ($children_yellow=0) and ($gsub_red=0) and ($gsub_yellow=0) and ( ($children_green>0) or ($gsub_green>0) )">
							<xsl:text>green</xsl:text>
						</xsl:when>
						<xsl:when test="($children_red=0) and ($gsub_red=0) and ( ($children_yellow>0) or ($gsub_yellow>0) )">
							<xsl:text>yellow</xsl:text>
						</xsl:when>
						<xsl:otherwise>
							<xsl:text>red</xsl:text>
						</xsl:otherwise>
					</xsl:choose>
				</xsl:for-each>		
			</xsl:attribute>
			
			<xsl:attribute name="id">			
				<xsl:value-of select="@id"/>
			</xsl:attribute>
			<xsl:attribute name="is_leave">	
				<xsl:value-of select="not(boolean(count(./req)))"/>
			</xsl:attribute>
			<xsl:attribute name="dummy">	
				<xsl:choose>
					<xsl:when test="@dummy">
						<xsl:value-of select="@dummy"/>
					</xsl:when>
					<xsl:otherwise>
						<xsl:text>0</xsl:text>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:attribute>
			<xsl:attribute name="struct">	
				<xsl:choose>
					<xsl:when test="@struct">
						<xsl:value-of select="@struct"/>
					</xsl:when>
					<xsl:otherwise>
						<xsl:text>0</xsl:text>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:attribute>
			<xsl:copy-of select="./descr"/>
			<xsl:copy-of select="$gsub_ns"/>
		</xsl:copy>
		
		<xsl:copy-of select="$sub_ns"/>
	</xsl:template>	<!-- END OF TEMPLATE "req_pre" -->

	<xsl:template match="req"> <!-- TEMPLATE "req" -->
		<xsl:variable name="req_color">
			<xsl:choose>
				<xsl:when test="@covered='brown'">
					<xsl:text>#FF0000</xsl:text>
				</xsl:when>
				<xsl:when test="@covered='red'">
					<xsl:text>#000000</xsl:text>
				</xsl:when>
				<xsl:when test="@covered='yellow'">
					<xsl:text>#888800</xsl:text>
				</xsl:when>
				<xsl:when test="@covered='gray'">
					<xsl:text>#888888</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:text>#008800</xsl:text>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>

		<!-- id -->
		<xsl:element name="font">
			<xsl:attribute name="color">
				<xsl:value-of select="$req_color"/>
			</xsl:attribute>
			<xsl:value-of select="@id"/>
			<xsl:if test="@struct=1">
				<xsl:text> (struct)</xsl:text>
			</xsl:if>
			<xsl:if test="@covered='brown'">
				<xsl:text> (FAILED)</xsl:text>
			</xsl:if>
			
		</xsl:element>
		
		<!-- descr -->
		<xsl:for-each select="descr"> 
			<br/>
			<font color="#000088">
			<xsl:value-of select="." disable-output-escaping="yes"/>
			</font>
		</xsl:for-each>
		
		<!-- gsub -->
		<xsl:if test="count(./gsub)>0">
			<br/><xsl:text>Generalizes:</xsl:text>
			<ul>
			<xsl:for-each select="./gsub">
				<li><xsl:apply-templates select="."/></li>
			</xsl:for-each>
			</ul>
		</xsl:if>
		
		<!-- req -->
		<ul>
		<xsl:for-each select="./req">
			<li><xsl:apply-templates select="."/></li>
		</xsl:for-each>
		</ul>

	</xsl:template> <!-- END OF TEMPLATE "req" -->

	<xsl:template name="gsub_pre"> <!-- TEMPLATE "gsub_pre" -->
		<xsl:variable name="cid" select="@id"/>
		<xsl:variable name="cid2" select="concat('?',$cid)"/>

		<xsl:copy>
			<xsl:attribute name="covered">
			
				<xsl:for-each select="$root"> <!-- Dummy foreach -->	
					<xsl:variable name="nod" select="key('map_names',$cid)" />
					<xsl:variable name="nod2" select="key('map_names',$cid2)" />
					<xsl:variable name="nod3" select="key('map_failures',$cid)" />
					<xsl:choose>
						<xsl:when test="count($nod3)!=0">
							<xsl:text>brown</xsl:text>
						</xsl:when>
						<xsl:when test="count($nod)!=0">
							<xsl:text>green</xsl:text>
						</xsl:when>
						<xsl:when test="count($nod2)!=0">
							<xsl:text>yellow</xsl:text>
						</xsl:when>
						<xsl:otherwise>
							<xsl:text>red</xsl:text>
						</xsl:otherwise>
					</xsl:choose>
				</xsl:for-each>		
			</xsl:attribute>
			
			<xsl:attribute name="id">			
				<xsl:value-of select="@id"/>
			</xsl:attribute>
		</xsl:copy>		
	</xsl:template>	<!-- END OF TEMPLATE "gsub_pre" -->
	
	<xsl:template match="gsub"> <!-- TEMPLATE "gsub" -->
		<xsl:variable name="req_color">
			<xsl:choose>
				<xsl:when test="@covered='brown'">
					<xsl:text>#FF0000</xsl:text>
				</xsl:when>
				<xsl:when test="@covered='red'">
					<xsl:text>#000000</xsl:text>
				</xsl:when>
				<xsl:when test="@covered='yellow'">
					<xsl:text>#888800</xsl:text>
				</xsl:when>
				<xsl:when test="@covered='gray'">
					<xsl:text>#888888</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:text>#008800</xsl:text>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable> 

		<xsl:element name="font">
			<xsl:attribute name="color">
				<xsl:value-of select="$req_color"/>
			</xsl:attribute>
			<xsl:value-of select="@id"/>
		</xsl:element>
	</xsl:template> <!-- END OF TEMPLATE "gsub" -->
	
	<xsl:template name="plus">
		<xsl:param name="n_id"/>
		<xsl:param name="roll"/>
		<xsl:text>[</xsl:text>
		<xsl:element name="a">
			<xsl:attribute name="onclick">
				<xsl:text disable-output-escaping="yes">return show('</xsl:text>
				<xsl:value-of select="$n_id"/>
				<xsl:text disable-output-escaping="yes">',this)</xsl:text>
			</xsl:attribute>
			<xsl:attribute name="href">
				<xsl:text>#</xsl:text>
			</xsl:attribute>
			<xsl:choose>
				<xsl:when test="$roll">
					<xsl:text disable-output-escaping="yes">&amp;#150;</xsl:text>
				</xsl:when>
				<xsl:otherwise>
					<xsl:text>+</xsl:text>
				</xsl:otherwise>
			</xsl:choose>	
		</xsl:element>
		<xsl:text>]</xsl:text>
	</xsl:template>

</xsl:stylesheet>